

void Map_printer(multimap<int,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> a;
    vector<int> z;
    int x;
    lli sum=0;

    multimap<int,int> m1; //key -> value value->index
    multimap<int,int> m2;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        if(x == 0)
            z.push_back(x);
        else
            a.push_back(x);

        if(x%3 == 1)
            m1.insert({x,i});

        if(x%3 == 2)
            m2.insert({x,i});

        sum+=x;
    }

    //cout<<" sum = "<<sum<<"\n";
    //Map_printer(m1);
    // Map_printer(m2);

    if(z.size() == 0)
        cout<<"-1\n";
    else
    {
        if(sum%3 == 0)
        {
            sort(a.begin(),a.end(),greater<int>());
                for(auto i = a.begin(); i!=a.end(); i++)
                    cout<<*i;
                if(a.size()!=0)
                {
                    for(int i=0; i<z.size(); i++)
                        cout<<z[i];
                }
                else
                    cout<<0;
        }
        else if(sum%3 == 1)
        {
            if(m1.size() >= 1)
            {
                a.erase(a.begin() + m1.begin()->second);
                sort(a.begin(),a.end(),greater<int>());
                for(auto i = a.begin(); i!=a.end(); i++)
                    cout<<*i;
                if(a.size()!=0)
                {
                    for(int i=0; i<z.size(); i++)
                        cout<<z[i];
                }
                else
                    cout<<0;
            }
            else if(m2.size() >= 2)
            {
                a.erase(a.begin()+m2.begin()->second);
                auto ptr = m2.begin();
                ptr++;
                auto to_erase2 = a.begin() + ptr->second - 1;

                if(to_erase2 != a.begin()-1 && to_erase2!=a.end())
                    a.erase(to_erase2);

                sort(a.begin(),a.end(),greater<int>());
                for(auto i = a.begin(); i!=a.end(); i++)
                    cout<<*i;
                if(a.size()!=0)
                {
                    for(int i=0; i<z.size(); i++)
                        cout<<z[i];
                }
                else
                    cout<<0;
            }
            else
                cout<<0;

        }
        else
        {
            if(m2.size() >= 1)
            {
                a.erase(a.begin() + m2.begin()->second);
                sort(a.begin(),a.end(),greater<int>());
                for(auto i = a.begin(); i!=a.end(); i++)
                    cout<<*i;
                if(a.size()!=0)
                {
                    for(int i=0; i<z.size(); i++)
                        cout<<z[i];
                }
                else
                    cout<<0;
            }
            else if( m1.size() >= 2 )
            {
                // cout<<"Erasing = "<<*(a.begin() + m1.begin()->second)<<"\n";
                a.erase(a.begin() + m1.begin()->second);

                auto ptr = m1.begin();
                ptr++;

                auto to_Erase2 = a.begin()+ptr->second - 1;
                // cout<<"Erasing = "<<*(a.begin()+ptr->second - 1)<<"\n";
                if(to_Erase2 != (a.begin()-1) && to_Erase2!=a.end())
                    a.erase(to_Erase2);

                sort(a.begin(),a.end(),greater<int>());
                for(auto i = a.begin(); i!=a.end(); i++)
                    cout<<*i;
                if(a.size()!=0)
                {
                    for(int i=0; i<z.size(); i++)
                        cout<<z[i];
                }
                else
                    cout<<0;
            }
            else
                cout<<0;
        }
    }
    return 0;
}
