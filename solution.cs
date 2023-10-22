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