class Graph {
    constructor(vertices) {
        this.vertices = vertices;
        this.adj = new Array(vertices).fill(null).map(() => []);
    }

    addEdge(u, v) {
        this.adj[u].push(v);
    }
}