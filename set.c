typedef unsigned long long Set;

void init(Set *set){
  *set &= 0;
  return;
}

void add(Set *set, int i){
  *set |= (1UL << i);
  return;
}

void has(Set set, int i){
  printf("%s %d\n",((set >> i) & 1) ? "set has":"set does not have", i);
  return;
}

Set setUnion(Set a, Set b){
  return (a | b);
}

Set setIntersect(Set a, Set b){
  return (a & b);
}

Set setDifference(Set a, Set b){
  return (a | b) - (a & b);
}