# Some properties of USPTO inventor names


These plots show the "tag" counts for each block for the entire
1975-2010 USPTO inventor names.

Let's look at some examples.

## Block on lastname

Suppose we have a series of names such as "Steve Smith" and
"Jim Smith". We can sort
these names alphabetically (*syn.* lexicographically) on the first name
"Steve" or the last name "Smith" or some combination of the first and
last names. When we sort the names (by whatever criteria), we can save
groups of names "tagged" with an identifier.

The action of sorting and grouping is commonly referred to as "blocking"
within the community of people who do that sort of things. 

The grouping rules matter. Taking only last names, for example "Smith",
puts "Steve" and "Jim" into the same block, which for purposes explained
later, would be tagged "SMITH".

For the entire USPTO inventor name set, the green crosses on the plot
below correspond to blocks of last names.



![Full range of blocking](https://raw.github.com/doolin/nameblock/master/doc/images/nameblocking.png "Blocking on USPTO inventor name")

### Block size versus block counts

The plots all show the same data, with each plot focusing on a different
view of the data. The full plot above shows how more than 9.3M names are
blocked. The values along the *x* axis are block sizes; along the
'''y''' axis, the count of blocks of a specific size. That is:

* Block size: the number of names grouped together with respect to a
specific block tag.
* Block count: the number of blocks having the same size.

For example, suppose we block on last name. Further, we a block with tag
SMITH containing Jim Smith and John Smith, and a block with tag JOHNSON
containing John Johnson. Then we have a block of size 2 and a block of
size 1. Now we find another block tagged JONES containing Joe Jones and
Jerry Jones. Now we have two blocks of size two and one block of size
one.



As expected, the more specific the blocking criteria, the fewer number
of elements in each block, which can be seen as the values along the *y*
axis:

* Lastname only blocking: 177746 blocks have a single element, 71849
have only two elements. This case lumps "Steve Smith" and "Jim Smith"
into the same block.
* Lastname and first initial blocking: 462165 blocks have a single
element, 176783 have two elements. This case splits Steve and Jim Smith
into separate blocks, but would lump Jim Johnson and John Johnson into
the same block.
* Lastname and firstname blocking: 1360582 blocks have a single element,
436765 have two elements. This case would split Jim and John Johnson.


Let's take a closer look at the values where the block sizes are small
and the number of blocks for a given size is large.

## Partial

Here, we're zoomed in to the range of blocks which have between 1 and
100 elements (inclusive). As noted, there are a large number of blocks
with a single element, regardless of the blocking criteria.

Of note is how the slope differs with respect to the blocking rule.

![Full range of blocking](https://raw.github.com/doolin/nameblock/master/doc/images/onetohundred.png "Blocking on USPTO inventor name")

## Increasing uniqueness

Now we're taking a really close look at the "unique" end of the plot.

![Full range of blocking](https://raw.github.com/doolin/nameblock/master/doc/images/onetofifty.png "Blocking on USPTO inventor name")


## Summary


### Further reading

Name frequencies are a special case of word frequencies, and have many
of the same strange and beautiful properties. Here are a few links:

* [Zipf and Mandelbrot
(Wikipedia)](http://en.wikipedia.org/wiki/Zipf's_law)


