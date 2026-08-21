class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int x = q1.front();
        q1.pop();

        swap(q1, q2);
        return x;
    }

    int top() {
        int x = pop();
        push(x);
        return x;
    }

    bool empty() {
        return q1.empty();
    }
};