/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Min Stack
    Link   : https://leetcode.com/problems/min-stack/description/
    
*/

class MinStack {

    /** initialize your data structure here. */
    private Stack<Long> iStack;
    private long minNum;
    public MinStack() {
        iStack = new Stack<>();
    }
    
    public void push(int x) {
        if(iStack.size()==0) {
            minNum=x;
            iStack.push((long)x);
        } else if(x<minNum) {
            iStack.push(2*(long)x - minNum);
            minNum = x;
        } else {
            iStack.push((long)x);
        }
    }
    
    public void pop() {
        if(iStack.size()==0) return; 
        long tValue = iStack.peek();
        if(tValue < minNum) {
            minNum = 2*minNum - tValue;
        }
        iStack.pop();
    }
    
    public int top() {
        if(iStack.size()==0) return 0;
        long tValue = iStack.peek();
        System.out.println("top : "+iStack.peek());
        System.out.println("min : "+minNum);
        if(tValue < minNum) {
            return (int)minNum;
        } 
        return (int)tValue;
    }
    
    public int getMin() {
        if(iStack.size()==0) return 0;
        return (int)minNum;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */