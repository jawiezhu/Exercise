// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

class MinStack {
private:
	stack<int> stk;
	stack<int> minstack;
public:
    void push(int x) {
        stk.push(x);
        if(minstack.empty())
        {
        	minstack.push(x);
        }else
        {
        	if(x<=minstack.top())
        		minstack.push(x);
        }
    }

    void pop() {
        if(stk.top()==minstack.top())
        {
        	stk.pop();
        	minstack.pop();
        }else
        {
        	stk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstack.top();
    }
};


//
// 相比传统stack（记为stk），为了记录最小值，需要再开一个最小值栈min。

// 需要注意的是：重复出现的最小值必须重复进min，不然出stk的时候，min可能会为空出错



// 基本思想是，按照进栈顺序来扫一遍的话，min值并不是一直在变化的，可能连着过了好多个元素，min并没有变。形式化地说，若令f(j) = min(arr[1..j])，那么f(j)的图像由若干条阶跃相连的水平线段组成。因此f(j)可以将每一条线段压缩到一个元素。
// 基本操作是：用两个栈，除了正常的stack之外，附加一个min-stack，保存当前的最小值。
// 数据栈压入元素时，如果小于min-stack最小值，则表明f(j)出现了一个阶跃（从左向右开始了一根新的水平线），要记录下来；否则只压到数据栈即可。
// 数据弹出的时候，检查是不是min-stack的栈顶元素，如果等于则表示回退过程中要经历阶跃了（从右到左回退到之前的某根水平线），min-stack也出栈。
// 性能分析：进栈出栈都是O(1)的，额外开销就是额外的空间。如果整个序列的最小元素最早进栈（譬如是一个递增序列进栈），这是最理想的了，O(1)的额外空间；如果是一个逆序的序列，就窘了，要一倍的额外空间。



struct node {
    int val;
    node *next;
    node *min;
    node():val(-1), next(NULL), min(NULL){}
    node(int v):val(v), next(NULL), min(NULL){}
};

class MinStack {
    node head;
    
public:
    void push(int x) {
        node *top, *pre;
        if(head.next == NULL) {
            head.next = new node(x);
            top = head.next;
            top->min = top;
        } else {
            pre = head.next;
            head.next = new node(x);
            top = head.next;
            top->next = pre;
            if (x <= pre->min->val) {
                top->min = top;
            } else {
                top->min = pre->min;
            }
        }
    }

    void pop() {
        if (head.next == NULL) return;
        node *tmp = head.next;
        head.next = tmp->next;
        delete tmp;
    }

    int top() {
        return head.next->val;
    }

    int getMin() {
        return head.next->min->val;
    }
};




