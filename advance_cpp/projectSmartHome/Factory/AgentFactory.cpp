#include "AgentFactory.h"
#include <dlfcn.h>
#include <string>

AgentFactory::AgentFactory(IServer* _server)
:m_server(_server)
{
}
AgentFactory::~AgentFactory()
{
}
IAgent* AgentFactory::MakeAgent(const IAgent::AgentConfig& _agentConfig)
{
	m_server = _agentConfig.m_server;
	std::string libPath = _agentConfig.m_type;
	libPath = "./" + libPath + ".so";
	void* handler = dlopen(libPath.c_str(), RTLD_LAZY);
	//error
	//make ctor
	IAgent* (*createAgent)();
	createAgent = (IAgent* (*)())dlsym(handler, "Create");
	IAgent* agent = createAgent();
	agent->Init(_agentConfig);
	return agent;
	//make init
}
/*
	void * handler = dlopen("./x.so", RTLD_LAZY);
	Y* (*funcCreate)(int,int);
	
	funcCreate = (Y*(*)(int,int))dlsym(handler,"create");
	Y* y = funcCreate(4,5);
	y->Print();
/*
	void *handle;
	double (*cosine)(double,double);
	char *error;

	handle = dlopen("../../../lib/libADD.so", RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
/*		exit(EXIT_FAILURE);
	}

	dlerror();

	cosine=(double(*)(double,double))dlsym(handle, "Calc");
	
	printf("%f\n",cosine(5,6));
	
	 dlclose(handle);
	 */
