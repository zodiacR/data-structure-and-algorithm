#!/usr/bin/python
#-*-coding:utf-8 -*-
#Author   : Zodiac
#Version  : 1.0
#Filename : itinerary.py
From = ["Chennai", "Bombay", "Delhi", "Goa"]
To = ["Banglore", "Delhi", "Goa", "Chennai"]

tickets = dict(zip(From, To))
reverse = dict(zip(tickets.values(), tickets.keys()))

print tickets
print reverse

#dest = reverse.keys();
#start = ""

#for place in tickets.keys():
    #if place not in dest:
        #start = place;
        #break
start = (set(From)-set(To)).pop()

dest = tickets[start]
while dest:
    print "%s->%s" %(start, dest)
    start = dest
    dest = tickets.get(dest, "")
