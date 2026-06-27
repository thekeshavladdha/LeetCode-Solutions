class Solution {
private:
    unordered_map<Node*, Node*> visited;
    
    Node* dfs(Node* node) {
        if (!node) return nullptr;
        if (visited.count(node)) return visited[node];
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
};