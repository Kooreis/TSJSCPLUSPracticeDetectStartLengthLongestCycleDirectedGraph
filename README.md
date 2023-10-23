# Question: How do you detect the start and length of the longest cycle in a directed graph? JavaScript Summary

The JavaScript code provided creates a class called Graph, which is used to represent a directed graph. The Graph class has methods for adding edges between vertices and for performing a Depth-First Search (DFS) to find the longest cycle in the graph. The DFS is implemented in the DFSUtil method, which is a recursive function that traverses the graph, marking vertices as visited and adding them to a path. If a vertex is encountered that has already been visited and is in the current path, a cycle is detected. The start and length of the cycle are calculated, and if this cycle is longer than any previously found, it is stored as the longest cycle. The findLongestCycle method initializes the search for the longest cycle by creating an array to track visited vertices and an empty path, then calling DFSUtil for each vertex in the graph. After the search is complete, findLongestCycle returns an object containing the start vertex and length of the longest cycle. The code at the end of the script creates a new Graph instance, adds edges to form a directed graph, and then calls findLongestCycle to find and log the longest cycle in the graph.

---

# TypeScript Differences

The TypeScript version of the solution differs from the JavaScript version in several ways:

1. Type Annotations: TypeScript version uses type annotations to ensure type safety. For example, the `addEdge` method in the TypeScript version specifies that its parameters `v` and `w` must be numbers.

2. Use of Map: The TypeScript version uses a `Map` to store the adjacency list, whereas the JavaScript version uses an array. This allows for more efficient lookups and insertions.

3. Different Problem Solving Approach: The JavaScript version finds the longest cycle in the graph, whereas the TypeScript version only checks if there is a cycle in the graph. The TypeScript version does not provide information about the start and length of the longest cycle.

4. Use of `!` Non-null Assertion Operator: In TypeScript version, `!` non-null assertion operator is used to tell TypeScript that the expression cannot be null or undefined. For example, `this.adjList.get(v)!`.

5. Private Modifier: The TypeScript version uses the `private` modifier to restrict the access of `adjList` property. This ensures that `adjList` can only be accessed within the `Graph` class.

6. Different Method Names: The JavaScript version uses `DFSUtil` and `findLongestCycle` methods, whereas the TypeScript version uses `DFSUtil` and `hasCycle` methods.

7. Different Logic in DFS: The JavaScript version uses a `path` array to keep track of the current path and checks if a node is in the current path to detect a cycle. The TypeScript version uses a `recStack` array to keep track of the nodes in the recursion stack to detect a cycle.

---

# C++ Differences

The C++ version of the solution uses a similar approach to the JavaScript version, using Depth-First Search (DFS) to find the longest cycle in a directed graph. However, there are some differences due to the language features and methods used in each version.

1. Data Structures: In JavaScript, arrays are used to represent the graph and the path. In C++, vectors and arrays are used. Vectors in C++ are similar to arrays in JavaScript, but they are more dynamic and provide many built-in functions.

2. Memory Management: In C++, memory for the graph, visited array, recursion stack, and parent array is allocated dynamically using the `new` keyword. In JavaScript, memory management is handled automatically.

3. Looping: In JavaScript, the `for...of` loop is used to iterate over the adjacency list of a vertex. In C++, a traditional `for` loop is used with an index to access elements.

4. Cycle Detection: In JavaScript, the `Array.prototype.includes()` method is used to check if a vertex is in the current path, indicating a cycle. In C++, a recursion stack (`recStack`) is used to keep track of the vertices in the current path.

5. Cycle Length and Start: In JavaScript, the cycle length and start are calculated using `Array.prototype.length` and `Array.prototype.indexOf()`. In C++, the cycle length is the size of the `tempCycle` vector and the start is the first vertex in the cycle.

6. Output: In JavaScript, the result is returned as an object with the start vertex and length of the longest cycle. In C++, the result is printed to the console using `cout`.

7. Error Handling: The C++ version includes a check for when no cycle is found and prints a message to the console. The JavaScript version does not include this check.

8. Function Definitions: In JavaScript, methods are defined inside the class using the method shorthand syntax. In C++, methods are defined outside the class using the scope resolution operator `::`.

9. Main Function: In C++, the main function is where the program starts execution. In JavaScript, the code is executed from top to bottom, and there is no need for a main function.

---
