# PlotBetaDiversity3D
# Language: C++
# Input: TXT
# Output: Directory
# Tested with: PluMA 1.0, GCC 4.8.4
# Dependency: Qiime 1.9.1, Python 2.7

PluMA plugin to compute beta-diversity of a set of samples using Qiime (Caporaso et al, 2010), producing 3D plots.

The plugin accepts as input a TXT file containing lines with keywords and values (whitespaced-delimited):
biomfile: OTUs and abundances (BIOM)
tree: Phylogenetic tree (TRE)
mapping: Metadata (CSV)
depth: Sampling Depth (integer)


The output for this plugin is a directory, where plots will be stored.

Note: This plugin works with Qiime 1, which is only compatible with Python 2.  Since PluMA has been
upgraded to use Python 3, you must set the following two environment variables for this to work:

PYTHON2_SITE_PACKAGES
PYTHON2_DIST_PACKAGES

This way the Python 2 environment can be loaded and unloaded properly at runtime.
