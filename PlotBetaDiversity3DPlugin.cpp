#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "PlotBetaDiversity3DPlugin.h"

void PlotBetaDiversity3DPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
 
}

void PlotBetaDiversity3DPlugin::run() {
   
}

void PlotBetaDiversity3DPlugin::output(std::string file) {
//beta_diversity.py -i filtered_otu_table.biom -m euclidean,weighted_unifrac,unweighted_unifrac -t rep_set.tre -o beta_div
   std::string command = "beta_diversity_through_plots.py ";
 command += "-i "+std::string(PluginManager::prefix())+parameters["biomfile"];
 command += " -m "+std::string(PluginManager::prefix())+parameters["mapping"];
 command += " -e "+parameters["depth"];
 for (int i = 0; i < metrics.size(); i++) {
    command += metrics[i];
    if (i != metrics.size()-1){command += ",";}
    else {command += " ";}
 }
 command += " -t "+std::string(PluginManager::prefix())+parameters["tree"]+" ";
 command += "-f -o "+file+"; cp "+file+"/*.txt "+file+"/..";//; export PYTHONPATH=OLDPATH";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<PlotBetaDiversity3DPlugin> PlotBetaDiversity3DPluginProxy = PluginProxy<PlotBetaDiversity3DPlugin>("PlotBetaDiversity3D", PluginManager::getInstance());
