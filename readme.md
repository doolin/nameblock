# Blocking test code

`nameblock` is a toy c++ code investigating properties of USPTO
inventor name data. The main objectives are:

1. Explore the time and space behavior of blocking under various predicates.
2. Develop a best-practice implementation.
3. Examine simple statistics collected from blocking and related
   processing.

At the moment, the code will process 9.3M rows of inventor
data into about 1M blocks, in 10 minutes on a single processor,
using about 15G of ram.

Timewise, this is fine, but the memory consumption needs to be
cut by 60+% if possible.


## TODO

Following the spirit of Readme Driven Development, here's a
few tasks outstanding:

* Implement a limited similarity comparison.
* Given similarity comparisons, implement cohesion as the mean
  of pairwise comparison probabilities. (Likelihood table
  will need generating elsewhere.) \chi would be a good
  letter for denoting cohesion.

## License

Dual license GPL and MIT.

Enjoy!
