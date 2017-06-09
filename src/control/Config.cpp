#include "Config.hpp"
#include <fstream>
#include <iostream>

using namespace std;

Config::Config(string configFile)
  : configFile(configFile) {
  read();
}

void Config::read() {
  configuration.clear();
  ifstream fin(configFile);
  NameValue conf;
  string name, value;
  while (!fin.eof()) {
    fin >> conf.name >> conf.value;
    if (fin.eof()) {
      break;
    }
    configuration.push_back(conf);
  }
}

void Config::save() {
  ofstream fout(configFile);
  for (const NameValue &conf: configuration) {
    fout << conf.name << " " << conf.value << endl;
  }
}
