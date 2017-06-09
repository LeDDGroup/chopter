#include <string>
#include <vector>

class Config {
  struct NameValue {
    std::string name, value;
  };
  std::string configFile;
  std::vector<NameValue> configuration;
public:
  Config(std::string configFile);
  std::string getValue(const std::string &option) const;
  void setValue(const std::string &option, const std::string &value);
  void save();
  void read();
};
