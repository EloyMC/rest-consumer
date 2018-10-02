// Copyright 2018 Uncle Ben

#include <iostream>
#include <string>
#include <sstream>
#include "Foo.h"
#include "../include/Main.h"
#include "../include/RestConsumer.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;

void printTree(boost::property_tree::ptree const& pt) {
    using boost::property_tree::ptree;
    ptree::const_iterator end = pt.end();
    for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
        std::cout << it->first << ": " \
            << it->second.get_value<std::string>() << std::endl;
        printTree(it->second);
    }
}

int main() {
    std::cout << Foo::bar("test") << "\n";

    RestConsumer consumer("http://localhost:8080/api/todo/");

    std::stringstream stream;

    stream << consumer.getRequest(1);

    pt::ptree tree;

    pt::read_json(stream, tree);

    printTree(tree);
}
