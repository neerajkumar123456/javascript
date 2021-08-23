def fun(a,n):
    if(n==1):
        return n
    i=0
    j=0
    while(i<(n-1)):
        while(j<(n-1)and (a[i+1]<=a[i])):   # [100, 180, 260, 310, 40, 535, 695]
            i+1
        if(i==n-1):
            break
        buy=i
        i+=1
        while ((i < n) and (a[i] >= a[i - 1])):
            i += 1
        sell=i-1
        print("Buy on : ",str(buy) +' day' +'   ',"Sell on : ",str(sell) +' day')


print('enter the stock amount ')
#a=list(map(int,input().split()))
a= [100, 180, 260, 310, 40, 535, 695]
n=len(a)

print(a)
fun(a,n)
