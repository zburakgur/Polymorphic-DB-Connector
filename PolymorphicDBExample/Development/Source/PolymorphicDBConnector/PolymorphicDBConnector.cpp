
#include "stdafx.h"
#include "PolymorphicDBConnector.h"

using namespace PDb;

void PDbParam::setValue(const int value)
{
	int * ptrTmp = new int;
	*ptrTmp = value;

	this->value = (void *)ptrTmp;
}

void PDbParam::setValue(const _int64 value)
{
	_int64 * ptrTmp = new _int64;
	*ptrTmp = value;

	this->value = (void *)ptrTmp;
}

void PDbParam::setValue(const string & value)
{
	string * ptrTmp = new string;
	*ptrTmp = value;

	this->value = (void *)ptrTmp;
}

void PDbParam::setValue(const float value)
{
	float * ptrTmp = new float;
	*ptrTmp = value;

	this->value = (void *)ptrTmp;
}

void PDbParam::setValue(const double value)
{
	double * ptrTmp = new double;
	*ptrTmp = value;

	this->value = (void *)ptrTmp;
}

int PDbParam::getIntValue()
{
	return *((int *)value);
}


__int64 PDbParam::getBigIntValue()
{
	return *((__int64 *)value);
}

float PDbParam::getFloatValue()
{
	return *((float *)value);
}

double PDbParam::getDoubleValue()
{
	return *((double *)value);
}

const string & PDbParam::getStringValue()
{
	return *((string *)value);
}

DataType PDbParam::getType()
{
	return type;
}

/************************************************/

void PDbException::setMsg(const string &msg)
{
	this->msg = msg;
}

const string & PDbException::getMsg() const
{
	return msg;
}


void PDbException::setErrCode(int errCode)
{
	this->errCode = errCode;
}

int PDbException::getErrCode() const
{
	return errCode;
}

/************************************************/
