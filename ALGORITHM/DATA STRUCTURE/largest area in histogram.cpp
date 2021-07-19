int solve(int n)
{
    int tp,area=0;
    stack<int> st;
    int i;
    for(i=0;i<n;)
    {
        if(st.empty()|| num[st.top()]<=num[i])
            st.push(i++);
        else
        {
            tp=st.top();
            st.pop();
            area=max(area,num[tp]*(st.empty()? i: i-st.top()-1));
        }
    }
    while(!st.empty())
    {
        tp=st.top();
        st.pop();
        area=max(area,num[tp]*(st.empty()? i: i-st.top()-1));
    }
    return area;
}
