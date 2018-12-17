struct Couple {
float a;
float b;

};

program PROG {
version VERS {
    float add(Couple data)=1;
    float mult(Couple data)=2;

    }=1;
}=1;
