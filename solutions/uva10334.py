# Original Logic:
# ll arr[1005][4] = {0};
#
# arr[0][0] = 1; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 1;
#
# arr[1][0] = 0; arr[1][1] = 1; arr[1][2] = 1; arr[1][3] = 2;
#
# for(int i = 2; i < 1002; ++i){
#     if(i%2 == 0)
#         arr[i][0] = arr[i-1][1] + arr[i-1][2], arr[i][1] = arr[i-1][2], arr[i][2] = 0, arr[i][3] = arr[i][0] + arr[i][1] + arr[i][2];
#     else
#         arr[i][2] = arr[i-1][0] + arr[i-1][1], arr[i][1] = arr[i-1][0], arr[i][0] = 0, arr[i][3] = arr[i][0] + arr[i][1] + arr[i][2];
# }
#
# ll a;
# while(!cin.eof()){
#     cin >> a;
#     if(cin.eof())
#         break;
#     cout << arr[a][3] << endl;
# }

# This is nothing but fibonacci series

fibs = [1]*1005
def fib():
    fibs[0] = 1
    fibs[1] = 2
    for i in range(2, 1005):
        fibs[i] = fibs[i-1] + fibs[i-2]

fib()

while True:
    try:
        x = int(input())
        print(fibs[x])
    except EOFError:
        break
