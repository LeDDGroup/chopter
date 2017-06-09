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

void Config::setValue(const string &option, const string &value) {
  for (NameValue &conf: configuration) {
    if (conf.name == option) {
      conf.value = value;
      return;
    }
  }
  NameValue conf = { option, value };
  configuration.push_back(conf);
}

string Config::getValue(const string &option) const {
  for (const NameValue &conf: configuration) {
    if (conf.name == option) {
      return conf.value;
    }
  }
  return "NO_VALUE";
}
