struct node
{
	bool endmark;
	node *next[27];
	node cnt[27];
	node()
	{
		endmark=false;
		for(int i=0;i<26;i++) next[i]=NULL;
	}
}*root;

// inserting function
void insert(char *str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endmark=true;
}

//searching function

bool khujo(char *str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
		if(curr->next[id]==NULL) return false;
		curr=curr->next[id];
	}
	return curr->endmark;
}

//counting the number of common prefix
int mapo(char* str,int len)
{
    int id,man=0;
    node *cur=root;
    for(int i=0;i<len;i++)
    {
        id=str[i]-'a';
        if(man==len-1)
            return cur->cnt[id];
        if(cur->next[id]==NULL)
           return 0;
        cur=cur->next[id];
        man++;
    }
}
//memory clear function
void del(node *cur)
{
      for(int i=0;i<26;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;

         delete(cur) ;
}
int main(){

	puts("ENTER NUMBER OF WORDS");
	root=new node();
	int num_word;
	cin>>num_word;
	for(int i=1;i<=num_word;i++)
	{
		char str[50];
		scanf("%s",str);
		insert(str,strlen(str));
	}
	puts("ENTER NUMBER OF QUERY";);
	int query;
	cin>>query;
	for(int i=1;i<=query;i++)
	{
		char str[50];
		scanf("%s",str);
		if(khujo(str,strlen(str)))	puts("FOUND");
		else puts("NOT FOUND");
	}
	del(root); //ট্রাইটা ধ্বংস করে দিলাম
	return 0;
}
