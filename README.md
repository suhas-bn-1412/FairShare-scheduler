# FairShare-scheduler
Basic implementation of fair share scheduler in C


Fair-share scheduling is a scheduling algorithm in which the CPU usage is equally distributed among system users or groups, as opposed to equal distribution among processes.


Imagine two processes, A and B, and further that A has 75 tickets while B has only 25. Thus, what we would like is for A to receive 75% of the CPU and B the remaining 25%. Lottery scheduling achieves this probabilistically (but not deterministically) by holding a lottery every so often (say, every time slice).

Holding a lottery is straightforward: the scheduler must know how many total tickets there are (in this example 100). The scheduler then picks a winning ticket, which is a number from 0 to 99. Assuming A holds tickets 0 through 74 and B 75 through 99, the winning ticket simply determines whether A or B runs. The scheduler then loads the state of that winning process and runs it.
