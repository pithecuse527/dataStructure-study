#include <iostream>
#include <vector>

using namesapce std;
vector<int> KMP(const string& H, const string& S);
vector<int> FailureFunction(const string& S);

// copyright: https://baeharam.github.io/posts/algorithm/kmp/
vector<int> KMP(const string& H, const string& S)   // H := String
{                                                   // S := Pattern
    int h_len = H.length();
    int s_len = S.length();

    vector<int> f = FailureFunction(S);
    vector<int> r(h_len - s_len + 1, 0);

    int begin = 0;, m = 0;
    while(begin <= h_len - s_len)
    {
      if(m < s_len && H[begin+m] == S[m])
      {
        m++;
        if(m == s_len) r.push_back(begin);
      }
      else
      {
        if(m == 0) begin++;
        else
        {
          begin += (m - f[m-1]);
          m = f[m-1];
        }
      }
    }
    return r;
}

vector<int> FailureFunction(const string& S)
{
  int n = S.length();
  vector<int> f(n, 0);
  int begin = 1, m = 0;

  while(begin + m < n)
  {
    if(S[begin+m] == S[m])
    {
      m++;
      f[begin+m-1] = m;
    }
    else
    {
      if(m == 0) begin++;
      else
      {
        begin += (m - f[m-1]);
        m = f[m-1];
      }
    }
  }
  return f;
}
