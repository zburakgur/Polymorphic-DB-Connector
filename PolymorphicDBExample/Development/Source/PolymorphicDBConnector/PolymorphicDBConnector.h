//This header declares polymorphic database framework.

#ifndef _BASE_CONNECTOR_H
#define _BASE_CONNECTOR_H

#include "Defines.h"
#include <string>

using namespace std;

namespace PDb
{
	enum DataType{
		ptVarChar, ptTinyInt, ptInteger, ptBigInt, ptFloat, ptDouble, ptDateTime
	};

	/********************************************/

	/* Prepared Parameter Class */
	class _DLLExport PDbParam{

	private:

		void * value = NULL;
		DataType type;

	public:

		PDbParam(DataType type) :type(type){}
		~PDbParam(){ delete value; }

		void setValue(const int);
		void setValue(const __int64);
		void setValue(const string &);
		void setValue(const float);
		void setValue(const double);

		int getIntValue();
		__int64 getBigIntValue();
		float getFloatValue();
		double getDoubleValue();
		const string & getStringValue();
		
		DataType getType();
	};
	/********************************************/

	/* Base class for all framework classes */
	class PDbBaseObject{
		
	public:

		virtual PDbBaseObject * clone() = 0;

	};
	/*******************************************/

	/* Base connection class for polymorphic database framework */
	class PDbBaseConnection : public PDbBaseObject{

	protected:
		string address, db, user, pass;

	public:
		
		virtual void connect() = 0;
		virtual void disconnect() = 0;
		virtual void setConnString(
									const string &, const string &, 
									const string &, const string &
								  ) = 0;

	};
	/*******************************************/

	/* Base query class for polymorphic database framework */
	class PDbBaseQuery : public PDbBaseObject{

	public:

		virtual void setConn(PDbBaseConnection *) = 0;
		virtual void addSQL(const string &) = 0;
		virtual void clear() = 0;
		virtual PDbParam * const addParam(const string &, DataType) = 0;
		virtual string getFieldValueSTRING(const string &) = 0;
		virtual int getFieldValueINT(const string &) = 0;
		virtual __int64 getFieldValueBIGINT(const string &) = 0;
		virtual float getFieldValueFLOAT(const string &) = 0;
		virtual double getFieldValueDOUBLE(const string &) = 0;
		virtual string getFieldValueByIndexSTRING(int) = 0;
		virtual int getFieldValueByIndexINT(int) = 0;
		virtual __int64 getFieldValueByIndexBIGINT(int) = 0;
		virtual float getFieldValueByIndexFLOAT(int) = 0;
		virtual void executeQuery() = 0;
		virtual void executeNonQuery() = 0;
		virtual int getColumnCount() = 0;
		virtual string getColumnName(int) = 0;
		virtual bool read() = 0;
		virtual void prepare() = 0;
		virtual const string & getQuery() = 0;

	};

	/*******************************************/

	/* Class list of the frame work */
	struct PDbObjects{

		PDbBaseConnection * conn = NULL;
		PDbBaseQuery * query = NULL;

		~PDbObjects(){
			if (conn != NULL || query != NULL)
			{
				delete conn;
				delete query;
			}
		}
	};
	/********************************************/

	/* Polymorphic Database exception management class */
	class _DLLExport PDbException{

	private:
		string msg;
		int errCode = -1;			//default;

	public:
		PDbException(){};
		PDbException(const string &msg) :msg(msg){};
		PDbException(const string &msg, int errCode) :msg(msg), errCode(errCode){};
		void setMsg(const string &);
		const string & getMsg() const;
		void setErrCode(int);
		int getErrCode() const;
	};
}

#endif