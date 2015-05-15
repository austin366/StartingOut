#ifndef STARTINGOUTAPP_H
#define STARTINGOUTAPP_H

#include "MooseApp.h"

class StartingoutApp;

template<>
InputParameters validParams<StartingoutApp>();

class StartingoutApp : public MooseApp
{
public:
  StartingoutApp(const std::string & name, InputParameters parameters);
  virtual ~StartingoutApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* STARTINGOUTAPP_H */
