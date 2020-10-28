        #include <bits/stdc++.h>
        using namespace std;
        #define mod 1000000007
        #define ll long long int
        #define ld long double
        #define pb push_back
        #define ff first
        #define ss second
        #define all(x) x.begin(), x.end()
        #define mp map<ll, ll>
        #define um unordered_map<ll, ll>
        #define pll pair<ll, ll>
        #define st set<ll> 
        #define us unordered_set<ll>
        #define vt vector<ll>
        #define vp vector<pll>
        #define fl(i, x, y) for(long i=x;i<y;++i)
        #define flr(i, x, y) for(long i=x;i>=y;--i)
        // find in array if  possible
        bool is_possible(ll arr[],ll n,ll m,ll curr_min)
        {
            ll sum=0,students=1;
            for(ll i=0;i<n;i++)
            {
                if(arr[i] > curr_min)
                return false;
                if(sum + arr[i] > curr_min)
                {
                    students++;
                    sum = arr[i];

                    if(students>m)
                        return false;
                }
                else{
                    sum+=arr[i];
                }
            }
        return true;
        }
      
      ll binary_ssearch(ll arr[],ll n,ll m)
      {
        if(m>n)
            return -1;

        ll sum=0,ans=INT_MAX;

        for(ll i=0;i<n;i++)
            sum+=arr[i];

        ll s=arr[n-1],e=sum;

        while(s<=e)
        {
            ll mid = (s+e)/2;

            if(is_possible(arr,n,m,mid))
            {
                ans = min(ans,mid);
                e = mid - 1;
            }
            else
            s= mid + 1;
        }
        return ans;
      }

        int main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
                
            ll i,j,k,l,e,n,m,t;

            cin>>t;

            while(t--)
            {
               cin>>n>>m;

               ll arr[n];

               for(i=0;i<n;i++)
                cin>>arr[i];

               cout<<binary_ssearch(arr,n,m)<<endl;

            }
        return 0; 
        }
