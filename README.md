# D-Algorithm ATPG
D-Algorithm for automated test generation for faults in combinational circuits using path sensitization and backtracking. I plan on doing this entirely in C so the graph creation will be a big portion. I also plan on adding a subroutine for calculating controllability and observability for each node.

# Input Format

Circuit file, using a format similar to netlists. It should be easy enough to create a traversable graph of the circuit with resizing vectors.
```
INPUTS <number of input lines>
1 2 3 4 5 // numbering for every input line
OUTPUTS <number of output lines>
11 12 13 14 15 // number for every output line
NODES <number of nodes>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 // list of every node
GATES <number of gates>
<gatetype> <number of inputs> <list of input lines> <output lines>
AND 3 1 2 3 11
OR 2 2 3 6
FANOUT 3 3 7 8 9 // this has 1 input [3] and 3 outputs [7, 8, 9]
// etc etc
```

Fault list containing a list of which nodes to test for which faults
```
FAULTS <number of faults in the list>
<node number> <fault to test, sa0 or sa1>
6 0
6 1
7 0
8 1
//etc
```

The propagation of faults can be done with a queue, with the justification having a separate queue that gets called as a function inside the D-prop step, and another resizing vector for keeping track of the input vector. Need to have tables for each type of gate with the reduced 5-value truth table stored.

I don't know how the backward implication step backtracks at the moment so will look into the original paper later to figure out that step and add that.
