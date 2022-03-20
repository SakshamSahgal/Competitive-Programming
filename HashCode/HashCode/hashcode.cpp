#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

class Contributors
{
public:
    string name;
    lli no_of_skills=0;
    vector<pair<string,lli>> skill_name;
};

class Project
{
public:
    string name;
    lli nod;
    lli score;
    lli best_before;
    lli no_of_roles;
    vector<pair<string,lli>> roles_req;
};

class Completed
{
    public:
    string name;
    vector<string> partic;
};

int main()
{
    freopen("d_dense_schedule.in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lli c,p;
    cin>>c>>p;
    vector<Contributors> cc(c);
    vector<Project> pp(p);

    for(int i=0; i<c; i++)
    {
        cin>>cc[i].name;
        cin>>cc[i].no_of_skills;
        for(int j=0; j<cc[i].no_of_skills; j++)
        {
            string x;
            lli lev;
            cin>>x>>lev;
            cc[i].skill_name.push_back({x,lev});
        }
    }

    for(int i=0; i<p; i++)
    {
        cin>>pp[i].name;
        cin>>pp[i].nod;
        cin>>pp[i].score;
        cin>>pp[i].best_before;
        cin>>pp[i].no_of_roles;
        for(int j=0; j<pp[i].no_of_roles; j++)
        {
            string role_name;
            lli req_skill_lev;
            cin>>role_name;
            cin>>req_skill_lev;
            pp[i].roles_req.push_back({role_name,req_skill_lev});
        }
    }


    vector<Completed> comp;

    for(int i=0; i<p; i++) //projects
    {
        bool project_comp = 1;
        vector<string> people;
        map <string, int> m;
        for(auto k:pp[i].roles_req) //roles
        {
            bool roles_comp = 0;
            for(int j=0; j<c; j++) //contestants
            {
                for(auto l:cc[j].skill_name) //skills
                {
                    if(l.first == k.first && l.second >= k.second)
                    {
                        if(m.find(cc[j].name) == m.end()){
                            people.push_back(cc[j].name);
                            roles_comp = 1;
                            m[cc[j].name]++;
                            break;
                        }
                        //cout<<"contastant "<<cc[j].name<<" matches "<<pp[i].name<<"\n";
                    }
                }

                if(roles_comp == 1)
                    break;
            }

            if(!roles_comp)
            {
                project_comp = 0;
                break;
            }
        }

        if(project_comp)
        {
            Completed cx;
            cx.name = pp[i].name;
            cx.partic = people;
            comp.push_back(cx);
        }
    }

    cout<<comp.size()<<"\n";
    for(int i=0;i<comp.size();i++)
    {
        map <string, int> m;
        cout<<comp[i].name<<"\n";
        for(auto j:comp[i].partic){

                cout<<j<<" ";
            m[j]++;
        }
        cout<<"\n";
    }

    return 0;
}
