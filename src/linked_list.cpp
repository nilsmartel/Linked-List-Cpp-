#include <iostream> // Sry, needed it for the print function

/**
 * Node.
 * 
 * The fuck you expect?
 */
struct Node {
    int value;
    Node* next;
};

/**
 * Now this method would be (kind of, you know) 
 * private and I'm not gonna take the time, to write a method description
 * 
 * Naaaah, jk. It's a new node. 
 * 
 * @param value Value of the Node
 * @return Pointer to a heap allocated node. Don't use it ever. None of this code actually. Get help, use the stdlib
 */
Node* new_node(int value) {
    Node* node = new Node();
    node->value = value;
    node->next = 0;
    return node;
}

/**
 * Rule #1
 * Don't fucking implement Linked Lists agaaaaain
 */
class List {
    /**
     * Shush! Look away, private parts!!
     * 
     * quite nice cpp actually allows you to do that.
     */ 
    private:
    Node* head;

    public:
    List() {
        this->head = 0;
    }

    /**
     * Pushes an integer value to the end of the list
     */ 
    void push(int value) {
        if (!this->head) this->head = new_node(value);
        else {
            Node* current = this->head;
            while (current->next) current = current->next;
            current->next = new_node(value);
        }
    }

    /** 
     * shittiest Linked List ever, returns (-0) instead of a nullpointer
     */ 
    int peek() {
        if (this->head) {
            return this->head->value;
        }

        return (-0);
    }

    /**
     * Again, (-0) indicates an empty List
     * 
     * don't do that.
     */ 
    int pop() {
        if (this->head) {
            Node* node = this->head->next;
            int value = this->head->value;
            delete this->head;

            return value;
        }

        return (-0);
    }

    /**
     * prints List, what do you expect?
     */ 
    void print() {
        Node* node = this->head;

        while (node) {
            std::cout << node->value;
            node = node->next;
        }

        std::cout << std::endl;
    }

    /**
     * Frees all List Elements
     */
    void free() {
        while (this->pop() != -0);
    }
}; 

int main() {
    List list = List();

    for (int i=0; i<10; i++) list.push(i);

    list.print();

    list.free();
    return 0;
}