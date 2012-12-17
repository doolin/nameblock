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
puts "Steve" and "Jim" into the same block.

For the entire USPTO inventor name set, the green crosses on the plot
below correspond to blocks of last names.



![Full range of blocking](https://raw.github.com/doolin/nameblock/master/doc/images/nameblocking.png "Blocking on USPTO inventor name")

### Block size versus block counts

The plots all show the same data, with each plot focusing on a different
view of the data. The full plot above shows how more than 9.3M names are
blocked. The values along the *x* axis show the number of distinct tags
within each block of a certain size.

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




## Partial

![Full range of blocking](https://raw.github.com/doolin/nameblock/master/doc/images/onetohundred.png "Blocking on USPTO inventor name")

## Increasing uniqueness

![Full range of blocking](https://raw.github.com/doolin/nameblock/master/doc/images/onetofifty.png "Blocking on USPTO inventor name")



