#include "StartingoutApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<StartingoutApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

StartingoutApp::StartingoutApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  StartingoutApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  StartingoutApp::associateSyntax(_syntax, _action_factory);
}

StartingoutApp::~StartingoutApp()
{
}

extern "C" void StartingoutApp__registerApps() { StartingoutApp::registerApps(); }
void
StartingoutApp::registerApps()
{
  registerApp(StartingoutApp);
}

void
StartingoutApp::registerObjects(Factory & factory)
{
}

void
StartingoutApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
