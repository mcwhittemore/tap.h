namespace tap {
  
  void log(std::string str);
  void pass(bool pass, std::string str);
  int end();
  void start();
  int failing = 0;
  int counter = 1;

  void throwFail(void (*fptr)(), std::string str) {
    try {
      fptr();
      pass(true, str);
    }
    catch (const char* msg) {
      pass(false, str);
      std::cout << "  --- \n";
      std::cout << "  message: '" << msg << "'\n";
      std::cout << "  severity: fail\n";
      std::cout << "  ...\n";
    }
  }


  void pass(bool pass, std::string str) {
    if (pass) {
      std::cout << "ok " << counter << " " << str << "\n";
    }
    else {
      std::cout << "not ok " << counter << " " << str << "\n";
      failing = 1;
    }
    counter++;
  }

  void test(std::string str) {
    std::cout << str << "\n";
  }

  void start() {
    std::cout << "TAP version 13\n";
    failing = 0;
    counter = 1;
  }

  int end() {
    std::cout << "1.." << counter-1 << "\n";
    return failing;
  }
}
