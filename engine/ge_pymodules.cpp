///////////// Copyright © 2009 LodleNet. All rights reserved. /////////////
//
//   Project     : Server
//   File        : ge_pymodules.cpp
//   Description :
//      Exposes several engine elements to source
//
//   Created On: 9/1/2009 10:19:52 PM
//   Created By: Mark Chandler <mailto:mark@moddb.com>
////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>

//cbase replacement start
#include "basetypes.h"
#include "commonmacros.h"
#include "mathlib/mathlib.h"
#include "tier0/dbg.h"
#include "tier0/vprof.h"
#include "tier0/icommandline.h"
#include "tier1/strtools.h"
//cbase replacement end

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

namespace bp = boost::python;

#define REG( Name )	extern void init##Name(); PyImport_AppendInittab( #Name , & init##Name );	

void pyMsg(const char* msg)
{
	Msg(msg);
}

void pyWarning(const char* msg)
{
	Warning(msg);
}

BOOST_PYTHON_MODULE(HLUtil)
{
	bp::def("Msg", pyMsg);
	bp::def("Warning", pyWarning);
}

BOOST_PYTHON_MODULE(sv_engine)
{
	bp::def("Msg", pyMsg);
}

BOOST_PYTHON_MODULE(cl_engine)
{
	bp::def("Msg", pyMsg);
	bp::def("Warning", pyWarning);
}

extern "C"
{

void RegisterPythonModules()
{
	REG( HLUtil );
	REG( sv_engine );
	REG( cl_engine );
}

}