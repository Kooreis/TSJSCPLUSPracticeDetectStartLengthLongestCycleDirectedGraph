Here is a JavaScript solution using Depth-First Search (DFS) to detect the start and length of the longest cycle in a directed graph:

```javascript
class Graph {
    constructor(vertices) {
        this.vertices = vertices;
        this.adj = new Array(vertices).fill(null).map(() => []);
    }

    addEdge(u, v) {
        this.adj[u].push(v);
    }

    DFSUtil(v, visited, path) {
        visited[v] = true;
        path.push(v);

        for (let i of this.adj[v]) {
            if (!visited[i]) {
                this.DFSUtil(i, visited, path);
            } else if (path.includes(i)) {
                let cycleStart = path.indexOf(i);
                let cycleLength = path.length - cycleStart;
                if (cycleLength > this.longestCycle.length) {
                    this.longestCycle = path.slice(cycleStart);
                }
            }
        }

        path.pop();
        visited[v] = false;
    }

    findLongestCycle() {
        this.longestCycle = [];
        let visited = new Array(this.vertices).fill(false);
        let path = [];

        for (let i = 0; i < this.vertices; i++) {
            this.DFSUtil(i, visited, path);
        }

        return { start: this.longestCycle[0], length: this.longestCycle.length };
    }
}

let g = new Graph(4);
g.addEdge(0, 1);
g.addEdge(1, 2);
g.addEdge(2, 0);
g.addEdge(2, 3);
g.addEdge(3, 2);

console.log(g.findLongestCycle());
```

This script creates a directed graph and adds edges between vertices. It then uses Depth-First Search (DFS) to find the longest cycle in the graph. The `findLongestCycle` method returns an object with the start vertex and length of the longest cycle.