# Assignment week 2 - Big O Notation

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