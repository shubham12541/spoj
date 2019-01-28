import java.util.*;
import java.io.*;
import java.lang.Math;

class gss1{

    static Node[] st;

    public static void main(String[] args) throws IOException{

        // BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        Reader reader = new Reader();
        PrintWriter out = new PrintWriter(System.out, true);

        int n = reader.nextInt();
        // int n = Integer.parseInt(in.readLine());
        // String[] line = in.readLine().split(" ");

        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = reader.nextInt();
            // arr[i] = Integer.parseInt(line[i]);
        }

        int m = reader.nextInt();
        // int m = Integer.parseInt(in.readLine());

        st = new Node[4*n];

        buildST(arr, 0, n-1, 0);

        // for(int i=0;i<4*n;i++){
        //     if(st[i] == null){
        //         System.out.print("NULL" + "\t");
        //         continue;
        //     } 
        //     System.out.print(st[i].max + "\t");
        // }

        while(m-- > 0){
            // String[] temp = in.readLine().split(" ");
            int L = reader.nextInt();
            int R = reader.nextInt();
            // int L = Integer.parseInt(temp[0]);
            // int R = Integer.parseInt(temp[1]);
            L--;
            R--;

            Node ans = queryST(n, L, R);
            out.println(ans.max);
            // System.out.println(ans.max);
        }

    }

    static Node queryST(int n, int queryStart, int queryEnd){
        if(queryStart < 0 || queryEnd > n-1 || queryStart > queryEnd){
            return null;
        }

        return queryUtil(0, n-1, queryStart, queryEnd, 0);

    }

    static Node queryUtil(int segStart, int segEnd, int queryStart, int queryEnd, int stIndex){

        if(segStart >= queryStart && segEnd <= queryEnd){
            return st[stIndex];
        }

        if(segEnd < queryStart || segStart > queryEnd){
            return null;
        }

        int segMidIndex = getMid(segStart, segEnd);

        return combineNodes(
            queryUtil(segStart, segMidIndex, queryStart, queryEnd, 2*stIndex+1),
            queryUtil(segMidIndex + 1, segEnd, queryStart, queryEnd, 2*stIndex+2)
        );

    }

    static Node buildST(int[] arr, int startIndex, int endIndex, int stIndex){
        // leaf
        if(startIndex == endIndex){
            Node temp = new Node();
            temp.leftMax = arr[startIndex];
            temp.rightMax = arr[startIndex];
            temp.max = arr[startIndex];
            temp.sum = arr[startIndex];

            st[stIndex] = temp;

            return temp;
        }

        int midIndex = getMid(startIndex, endIndex);

        st[stIndex] = combineNodes(
            buildST(arr, startIndex, midIndex, 2*stIndex + 1),
            buildST(arr, midIndex + 1, endIndex, 2*stIndex + 2)
        );

        return st[stIndex];

    }
    

    static Node combineNodes(Node a, Node b){

        if(a==null && b==null) return null;
        if(a == null) return b;
        if(b == null) return a;

        Node temp = new Node();

        temp.leftMax = Math.max(a.leftMax, a.sum + b.leftMax);
        temp.rightMax = Math.max(b.rightMax, b.sum + a.rightMax);
        temp.sum = a.sum + b.sum;
        temp.max = Math.max( 
            Math.max(temp.leftMax, temp.rightMax),  
            Math.max( 
                Math.max(a.max, b.max), 
                a.rightMax + b.leftMax
            ) 
        );

        return temp;
    }

    static int getMid(int a, int b){
        return a + (b-a)/2;
    }

    static class Node{
        int leftMax, rightMax, sum, max;
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;private DataInputStream din;private byte[] buffer;private int bufferPointer, bytesRead;
        public Reader(){din=new DataInputStream(System.in);buffer=new byte[BUFFER_SIZE];bufferPointer=bytesRead=0;
            }public Reader(String file_name) throws IOException{din=new DataInputStream(new FileInputStream(file_name));buffer=new byte[BUFFER_SIZE];bufferPointer=bytesRead=0;
            }public String readLine() throws IOException{byte[] buf=new byte[64];int cnt=0,c;while((c=read())!=-1){if(c=='\n')break;buf[cnt++]=(byte)c;}return new String(buf,0,cnt);
            }public int nextInt() throws IOException{int ret=0;byte c=read();while(c<=' ')c=read();boolean neg=(c=='-');if(neg)c=read();do{ret=ret*10+c-'0';}while((c=read())>='0'&&c<='9');if(neg)return -ret;return ret;
            }public long nextLong() throws IOException{long ret=0;byte c=read();while(c<=' ')c=read();boolean neg=(c=='-');if(neg)c=read();do{ret=ret*10+c-'0';}while((c=read())>='0'&&c<='9');if(neg)return -ret;return ret;
            }public double nextDouble() throws IOException{double ret=0,div=1;byte c=read();while(c<=' ')c=read();boolean neg=(c=='-');if(neg)c = read();do {ret=ret*10+c-'0';}while((c=read())>='0'&&c<='9');if(c=='.')while((c=read())>='0'&&c<='9')ret+=(c-'0')/(div*=10);if(neg)return -ret;return ret;
            }private void fillBuffer() throws IOException{bytesRead=din.read(buffer,bufferPointer=0,BUFFER_SIZE);if(bytesRead==-1)buffer[0]=-1;
            }private byte read() throws IOException{if(bufferPointer==bytesRead)fillBuffer();return buffer[bufferPointer++];
            }public void close() throws IOException{if(din==null) return;din.close();}
        }
}
