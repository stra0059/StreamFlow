#include <cassert>
#include <iostream>
#include <string>

#include "ComponentBase.h"
#include "ComponentFactory.h"
#include "Ports.h"
#include "allComponentIncludes.h"

#include "Application.h"

int main() {
  using namespace StreamFlow;

  std::cout << StreamFlow::Factory::describe() << std::endl;

  Application app("put application name here");
  // add Component (or node) in the app
  app.addNode("WebcamProducer");
  app.addNode("ConsumerComponent");

  // connect app's components together
  app["WebcamProducer"]["out"] >> app["ConsumerComponent"]["in"];

  app.addNode("ProducerComponentINT");
  app.addNode("ConsumerComponentINT");
  app["ProducerComponentINT"]["out"] >> app["ConsumerComponentINT"]["in"];

  // ask for component port documentation
  std::cout << app["WebcamProducer"]["out"].doc() << std::endl;
  std::cout << app["ConsumerComponent"]["in"].doc() << std::endl;

  // describe the application
  std::cout << app.doc() << std::endl;

  // describe a component
  std::cout << app["WebcamProducer"].doc() << std::endl;

  // run the application, enjoy pipeline and parallelism;
  app.run();

  return 0;
}
