class Skiplist {
private:

    static const int MAX_LEVEL = 16;

    struct Node {
        int val;
        vector<Node*> next;

        Node(int val, int level) {
            this->val = val;
            next.resize(level, nullptr);
        }
    };

    Node* head;

    int randomLevel() {
        int level = 1;

        while ((rand() & 1) && level < MAX_LEVEL) {
            level++;
        }

        return level;
    }

public:

    Skiplist() {
        head = new Node(-1, MAX_LEVEL);
    }

    bool search(int target) {

        Node* curr = head;

        // Top se bottom
        for (int level = MAX_LEVEL - 1; level >= 0; level--) {

            while (curr->next[level] &&
                   curr->next[level]->val < target) {
                curr = curr->next[level];
            }
        }

        // Ab target ke just pehle hain
        curr = curr->next[0];

        return curr != nullptr &&
               curr->val == target;
    }

    void add(int num) {

        Node* update[MAX_LEVEL];
        Node* curr = head;

        // Har level pe previous node find karo
        for (int level = MAX_LEVEL - 1; level >= 0; level--) {

            while (curr->next[level] &&
                   curr->next[level]->val < num) {
                curr = curr->next[level];
            }

            update[level] = curr;
        }

        // Random height
        int newLevel = randomLevel();

        Node* newNode = new Node(num, newLevel);

        // Har level pe insert
        for (int level = 0; level < newLevel; level++) {

            newNode->next[level] = update[level]->next[level];

            update[level]->next[level] = newNode;
        }
    }

    bool erase(int num) {

        Node* update[MAX_LEVEL];
        Node* curr = head;

        // Previous nodes find karo
        for (int level = MAX_LEVEL - 1; level >= 0; level--) {

            while (curr->next[level] &&
                   curr->next[level]->val < num) {
                curr = curr->next[level];
            }

            update[level] = curr;
        }

        curr = curr->next[0];

        // Number exist hi nahi karta
        if (curr == nullptr || curr->val != num) {
            return false;
        }

        // Har level se node hatao
        for (int level = 0; level < MAX_LEVEL; level++) {

            if (update[level]->next[level] != curr) {
                break;
            }

            update[level]->next[level] = curr->next[level];
        }

        delete curr;

        return true;
    }
};