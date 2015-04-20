uint32_t* Decrypt (uint32_t* v, const uint32_t* k) {
  
    uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i;  /* set up */
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    
    for (i=0; i < 32; i++) {                         /* basic cycle start */
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
    
    if(DEBUG && LEVEL.Decrypt) {
        Serial.print("Decrypt::decryptMsg[0]=0x");
        Serial.print(v[0], HEX);
        Serial.print("\t");
        Serial.print("decryptMsg[1]=0x");
        Serial.print(v[1], HEX);
        Serial.println("");
        Serial.println("");
    }
    
    return(v);
}
