# Assignment week 2 - Big O Notation
Asumme that T(1) = 1
### 1. $T(n) = T(\frac{n}{2}) + 1$
* Asumme that: $2^{k}=n \rightarrow 2^{-k}n=1 \rightarrow k = \log_2 {n}$
    > $T(n) = T(\frac{n}{2}) + 1 = (T(\frac{n}{4})+1)+1=T(2^{-2}n)+2 =T(2^{-3}n)+3=...=T(2^{-k}n)+k=T(1) + \log_2 {n} = 1 + \log_2 {n}$ 
* With $C = 1+\log_2{e} ,\; f(n) = \log {n}, \;n_0 = e \rightarrow T(n)\le C.f(n) ,\; \forall n \ge n_0$ because of:  
    > - $1 = \log {e} \le \log {n} \; \forall n \ge e $  
    > - $\log_2 {n} =\log_2{e}.\log{n}$  
    > 
    >$\rightarrow T(n) =1 + \log_2 {n} \le \log {n} + \log_2{e}.\log{n} = (1+\log_2{e}) \log{n}, \; \forall n \ge e $ 

So,  <span style="color:red">$T(n) = O(\log{n})$</span>

---
### 2. $T(n) = 2T(\frac{n}{2}) + n$
* Asumme that: $2^{k}=n \rightarrow 2^{-k}n=1 \rightarrow k = \log_2 {n}$
    > $T(n) = 2T(\frac{n}{2}) + n = 2(2T(\frac{n}{4})+\frac{n}{2})+n=2^2T(2^{-2}n)+2n =2^3T(2^{-3}n)+3n=...=2^kT(2^{-k}n)+kn=nT(1)+n\log_2 {n}=n+n\log_2 {n}$ 
* With $C = 1+\log_2{e} ,\; f(n) =n \log {n}, \;n_0 = e \rightarrow T(n)\le C.f(n) ,\; \forall n \ge n_0$ because of:  
    > - $n = n.1 \le n\log{n}, \; \forall n \ge e $  
    > - $\log_2 {n} =\log_2{e}.\log{n}$  
    > 
    >$\rightarrow T(n) =n+n\log_2 {n} \le n\log{n} + n \log_2{e}.\log{n} = (1+\log_2{e})n\log{n}, \; \forall n \ge e $ 

So,  <span style="color:red">$T(n) = O(n\log{n})$</span>

---
### 2. $T(n) = 3T(\frac{n}{2}) + \log{n}$
* Asumme that: $2^{k}=n \rightarrow 2^{-k}n=1 \rightarrow k = \log_2 {n}$
> $T(n)=3T(\frac{n}{2}) + \log{n} = 3(3T(\frac{n}{4})+\log{\frac{n}{2}}+\log{n}=3^2T(2^{-2}n)+\log{n}+3\log{2^{-1}n} = ...=3^kT(2^{-k}n)+\sum_{i=0}^{k-1}3^i\log{2^{-i}n}\le 3^kT(2^{-k}n)+\sum_{i=0}^{k}3^i\log{2^{-i}n}$
* We have $2^{-k}n=1$ and $k = \log_2 {n}$, and $\log{x} < x, \; \forall x\ge 0$ so:
> $$T(n) \le 3^{\log_2 {n}}T(1)+\sum_{i=0}^{\log_2 {n}}3^i2^{-i}n$$
>$$\le n^{\log_2 {3}}+\sum_{i=0}^{\log_2 {n}}3^i(2^{-i}n)^{\log_2 {3}-0.5}$$
>$$=n^{\log_2 {3}}+n^{\log_2 {3}-0.5}\sum_{i=0}^{\log_2 {n}}3^i2^{-i\log_2 {3}}2^{0.5i}$$
>$$=n^{\log_2 {3}}+n^{\log_2 {3}-0.5}\sum_{i=0}^{\log_2 {n}}3^i3^{-i}2^{0.5i}$$
>$$=n^{\log_2 {3}}+n^{\log_2 {3}-0.5}\sum_{i=0}^{\log_2 {n}}2^{0.5i}$$ 
>$$=n^{\log_2 {3}}+n^{\log_2 {3}-0.5}\frac{2^{0.5(\log_2 {n}+1)}-1}{2^{0.5}-1}$$
>$$\le n^{\log_2 {3}}+n^{\log_2 {3}-0.5}\frac{2^{0.5(\log_2 {n}+1)}}{2^{0.5}-1}$$