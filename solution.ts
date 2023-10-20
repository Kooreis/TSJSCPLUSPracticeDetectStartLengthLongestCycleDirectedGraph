Here is a TypeScript solution for detecting the start and length of the longest cycle in a directed graph:

```typescript
class Graph {
    private adjList: Map<number, number[]>;

    constructor() {
        this.adjList = new Map();
    }

    addEdge(v: number, w: number) {
        if (!this.adjList.has(v)) {
            this.adjList.set(v, []);
        }
        this.adjList.get(v)!.push(w);
    }

    DFSUtil(v: number, visited: boolean[], recStack: boolean[]): boolean {
        visited[v] = true;
        recStack[v] = true;

        for (let i = 0; i < this.adjList.get(v)!.length; i++) {
            let w = this.adjList.get(v)![i];
            if (!visited[w] && this.DFSUtil(w, visited, recStack)) {
                return true;
            } else if (recStack[w]) {
                return true;
            }
        }
        recStack[v] = false;
        return false;
    }

    hasCycle(): boolean {
        let visited = new Array(this.adjList.size).fill(false);
        let recStack = new Array(this.adjList.size).fill(false);

        for (let i = 0; i < this.adjList.size; i++) {
            if (!visited[i] && this.DFSUtil(i, visited, recStack)) {
                return true;
            }
        }
        return false;
    }
}

let g1 = new Graph();
g1.addEdge(0, 1);
g1.addEdge(0, 2);
g1.addEdge(1, 2);
g1.addEdge(2, 0);
g1.addEdge(2, 3);
g1.addEdge(3, 3);

if (g1.hasCycle()) {
    console.log("Graph contains cycle");
} else {
    console.log("Graph doesn't contain cycle");
}
```

This solution uses Depth-First Search (DFS) to detect cycles in the graph. It maintains two boolean arrays, `visited` and `recStack`. `visited` is used to keep track of the visited nodes, and `recStack` is used to keep track of the nodes in the recursion stack. If a node is reached that is already in the recursion stack, then there is a cycle in the tree.