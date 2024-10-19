#include <iostream>
#include <vector>
using namespace std;

class graph
{
public:
    int edges[100][100];
    int s_v;
    graph(int n)
    {
        s_v = n;
        for (int i = 0; i < s_v; i++)
        {
            for (int j = 0; j < s_v; j++)
            {
                edges[i][j] = 0;
            }
        }
    }
    void add_edge(int x, int y, int w)
    {
        edges[x][y] = w;
    }
    void print()
    {
        for (int i = 0; i < s_v; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < s_v; j++)
            {
                if (edges[i][j] > 0)
                {
                    cout << j << "," << edges[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    void bft(int start)
    {
        bool visited_bft[100];
        for (int i = 0; i < s_v; i++)
        {
            visited_bft[i] = 0;
        }
        visited_bft[start] = 1;
        vector<int> q;
        q.push_back(start);
        while (!q.empty())
        {
            start = q.front();
            cout << start << " ";
            q.erase(q.begin()); // ลบจุดยอดที่อยู่ในคิวออกหลังจากใช้งานแล้ว
            for (int y = 0; y < s_v; y++)
            {
                if (edges[start][y] > 0 && visited_bft[y] == 0)
                {
                    visited_bft[y] = 1;
                    q.push_back(y);
                }
            }
        }
        cout << endl;
    }

    bool visited_dft[100];
    void sub_dft(int start)
    {
        cout << start << " ";
        visited_dft[start] = 1;
        for (int y = 0; y < s_v; y++)
        {
            if (edges[start][y] > 0 && visited_dft[y] == 0)
            {
                sub_dft(y);
            }
        }
    }

    void dft(int start)
    {
        for (int i = 0; i < 100; i++)
        {
            visited_dft[i] = 0;
        }
        sub_dft(start);
        cout << endl;
    }

    void sub_graph()
    {
        int num_sub_graph = 1;
        for (int i = 0; i < 100; i++)
        {
            visited_dft[i] = 0;
        }
        for (int y = 0; y < s_v; y++)
        {
            if (visited_dft[y] == 0)
            {
                cout << "\nSub Graph " << num_sub_graph << " : ";
                sub_dft(y);
                num_sub_graph++;
            }
        }
    }

    int n_in_degree[100];
    int t_edges[100][100];
    void in_degree()
    {
        for (int i = 0; i < s_v; i++)
        {
            n_in_degree[i] = 0; // รีเซ็ตค่า in-degree ทุกจุดยอด
        }

        for (int i = 0; i < s_v; i++)
        {
            for (int j = 0; j < s_v; j++)
            {
                if (edges[j][i] > 0) // ตรวจสอบเส้นเชื่อมที่เข้ามายังจุดยอด i
                {
                    n_in_degree[i]++;
                }
            }
        }

        // แสดงผลค่า in-degree
        cout << "In-degree of each vertex:" << endl;
        for (int i = 0; i < s_v; i++)
        {
            cout << "Vertex " << i << " : " << n_in_degree[i] << endl;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    graph g(n);
    char text;

    while (true)
    {
        cin >> text;

        if (text == 'e') // เพิ่มเส้นเชื่อม
        {
            int a, b, c;
            cin >> a >> b >> c;
            g.add_edge(a, b, c);
        }
        else if (text == 's') // แสดงโครงสร้างกราฟ
        {
        }
        else if (text == 'd') // การเดินกราฟแบบลำดับเชิงลึก (DFS)
        {
            int a;
            cin >> a;
            g.dft(a);
        }
        else if (text == 'b') // การเดินกราฟแบบลำดับเชิงกว้าง (BFS)
        {
            int a;
            cin >> a;
            g.bft(a);
        }

        else if (text == 'q') // ออกจากโปรแกรม
        {
            break;
        }
    }

    return 0;
}
