#include <cstdio>

#include <cstdlib>

#include <stdint.h>

#include <string>

#include <iostream>

#include <unistd.h>

#include <cassert>

#include <sys/time.h>

#include <stack>

#include <vector>

#include <set>

#include <list>

using namespace std;

typedef unsigned long long ull;

inline FILE& operator>>(FILE& f, char*& d)

{

    int s = 20;

    d = (char*)malloc(s);

    int chr;

    int i = 0;

    do

    {

        chr = fgetc(&f);

        if(chr == EOF)

            goto OPERATOR_RSHIFT_FILE_CHAR_PTR_end;

    }

    while(chr == '\n' || chr == '\r' || chr == '\t' || chr == ' ');

    do

    {

        if(i == s)

        {

            s *= 2;

            d = (char*)realloc(d, s);

        }

        d[i] = chr;

        chr = fgetc(&f);

        ++i;

    }

    while(chr != EOF && chr != '\n' && chr != '\r' && chr != '\t' && chr != ' ');

    OPERATOR_RSHIFT_FILE_CHAR_PTR_end:;

    d = (char*)realloc(d, i+1);

    d[i] = '\0';

    return f;

}

inline FILE& operator>>(FILE& f, char& chr)

{

    int x;

    do

    {

        x = fgetc(&f);

        if(x == EOF)

        {

            chr = '\0';

            return f;

        }

    }

    while(x == '\n' || x == '\r' || x == '\t' || x == ' ');

    chr = x;

    return f;

}

inline FILE& operator>>(FILE& f, int& x)

{

    char *d;

    f >> d;

    x = atoi(d);

    free(d);

    return f;

}

inline FILE& operator>>(FILE& f, ull& x)

{

    fscanf(&f, "%llu", &x);

    return f;

}

inline FILE& operator>>(FILE& f, double x)

{

    char *d;

    f >> d;

    x = atof(d);

    free(d);

    return f;

}

inline FILE& operator>>(FILE& f, long double& x)

{

    fscanf(&f, "%LE", &x);

    return f;

}

inline FILE& operator>>(FILE& f, string& str)

{

    char *d;

    f >> d;

    str.~string();

    new (&str) string(d);

    free(d);

    return f;

}

inline FILE& operator<<(FILE& f, const char *str)

{

    fputs(str, &f);

    return f;

}

inline FILE& operator<<(FILE& f, int x)

{

    fprintf(&f, "%d", x);

    return f;

}

inline FILE& operator<<(FILE& f, ull x)

{

    fprintf(&f, "%llu", x);

    return f;

}

inline FILE& operator<<(FILE& f, double x)

{

    fprintf(&f, "%E", x);

    return f;

}

inline FILE& operator<<(FILE& f, long double x)

{

    fprintf(&f, "%LE", x);

    return f;

}

inline FILE& operator<<(FILE& f, const string& str)

{

    f << str.c_str();

    return f;

}

inline FILE& operator<<(FILE& f, char c)

{

    fputc(c, &f);

    return f;

}

struct _endofline

{

} eol;

struct _flush

{

} clearbuff;

inline FILE& operator<<(FILE& f, const __typeof__(eol)&)

{

    fputc('\n', &f);

    fflush(&f);

    return f;

}

inline FILE& operator<<(FILE& f, const __typeof__(clearbuff)&)

{

    fflush(&f);

    return f;

}

FILE& lin(*stdin);  // low-level-in

FILE& lout(*stdout);    // low-level-out

typedef pair<int,int> PII;

template<typename T>

inline T pred(T t)

{

    --t;

    return t;

}

template<typename T>

inline T succ(T t)

{

    ++t;

    return t;

}

vector< int > adj;

vector< list<int> > adjr;

vector< bool > visited;

vector< vector<int> > components;

vector< vector<int> > circles;

void visit(int x)

{

    if(visited[x])

        return;

    visited[x] = true;

    components.back().push_back(x);

    for(list<int>::iterator i = adjr[x].begin(); i != adjr[x].end(); ++i)

        visit(*i);

    visit(adj[x]);

}

int searchCircle(int comp, int x)

{

    if(visited[x])

    {

        circles[comp].push_back(x);

        return x;

    }

    visited[x] = true;

    {

        int r = searchCircle(comp, adj[x]);

        if(r == -2)

            return -2;

        if(r == x)

            return -2;

        if(r >= 0)

        {

            circles[comp].push_back(x);

            return r;

        }

    }

    return -1;

}

vector<PII> treevres;

int treev(int x, bool in)

{

//     cerr << "tv: " << x << " " << in << endl;

    if(in && treevres[x].first != -1)

        return treevres[x].first;

    else if(!in && treevres[x].second != -1)

        return treevres[x].second;

    int res = (in ? 1 : 0);

    assert(x >= 0 && x < adjr.size());

    for(list<int>::iterator i = adjr[x].begin(); i != adjr[x].end(); ++i)

        res += min(treev(*i, true), treev(*i, !in));

    if(in)

        treevres[x].first = res;

    else

        treevres[x].second = res;

    return res;

}

int main()

{

    int t;

    lin >> t;

    for(int _i = 0; _i != t; ++_i)

    {

        int n;

        lin >> n;

        adj.assign(n, 0);

        adjr.assign(n, list<int>());

        visited.assign(n, false);

        components.clear();

        for(int j = 0; j != n; ++j)

        {

            int k;

            lin >> k;

            --k;

            adj[j] = k;

            adjr[k].push_back(j);

        }

        int cnt = 0;

        for(int i = 0; i != n; ++i)

        {

            if(!visited[i])

            {

                components.resize(components.size() + 1);

                visit(i);

            }

        }

        visited.assign(n, false);

        circles.assign(components.size(), vector<int>());

        treevres.assign(n, make_pair(-1, -1));

        for(int i = 0; i != components.size(); ++i)

        {

            searchCircle(i, components[i].front());

            vector<int> treeValue;

            int sum = 0;

//             cerr << "Circle:";

            for(vector<int>::iterator j = circles[i].begin(); j != circles[i].end(); ++j)

            {

//                 cerr << " " << *j;

                int nxt = (j == pred(circles[i].end()) ? circles[i].front() : *succ(j));

//                 for(vector<int>::iterator k = adjr[*j].begin(); k != adjr[*j].end(); ++k)

//                     cerr << "r" << *k << endl;

                adjr[*j].remove(nxt);

//                 for(vector<int>::iterator k = adjr[*j].begin(); k != adjr[*j].end(); ++k)

//                     cerr << "R" << *k << endl;

                sum += treev(*j, true);

                treeValue.push_back(treev(*j, false) - treev(*j, true));

            }

//             cerr << endl;

//             cerr << sum << endl;

            int mmin = 1000000000;

            int sumEven = 0, sumOdd = 0;

            bool even = true;

            int best = 0, obest = 0;

            for(vector<int>::iterator j = succ(treeValue.begin()); j != treeValue.end(); ++j)

            {

                if(obest + *j < best)

                {

                    int tmpbest = best;

                    best = obest + *j;

                    obest = tmpbest;

                }

                else

                    obest = best;

            }

            int obest2 = 0, best2 = 0;

            for(vector<int>::iterator j = treeValue.begin(); j != pred(treeValue.end()); ++j)

            {

                if(obest2 + *j < best2)

                {

                    int tmpbest = best2;

                    best2 = obest2 + *j;

                    obest2 = tmpbest;

                }

                else

                    obest2 = best2;

            }

            cnt += min(best, best2);

            cnt += sum;

        }

        lout << cnt << eol;

    }

}
