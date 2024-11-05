const int MAXE=1024;

class vector{

    private:
      int unsigned dimension;     	    
      double elementos[MAXE];
    public:
       vector(); 
			 
//GETTERS
      int getDimension();	
      double getElemen(int unsigned pos);
			double mayorElem();
			int unsigned frecElem(double n);
	   	//Busquedas	
        int unsigned busqLineal(double n);
				int unsigned busqLinealOrdAsc(double n);
				int unsigned busqBinaria(double n);							
				        			        			  
//SETTERS
      void setDimension(int unsigned dim2);
      void modElemen(int unsigned pos, double ele);
			void elimElem(int unsigned pos);
      void insertElem(int unsigned pos, double ele);
			void exchangeElement(int unsigned posA , int unsigned posB);
			//Ordenamientos
			void exchangeSort();
			void selectionSort();		
			void shellSort();	
	 		void MergeSort();
	  	void Mezcla(int unsigned i,int unsigned m,int unsigned f);
			void MSort(int unsigned i , int unsigned f);	
 };
 //constructor
 
 vector::vector(){
   dimension = 0;
 }
 
 //setters

 void vector::setDimension(int unsigned dim2){
 	 if(dim2>=0 && dim2<=MAXE){
		dimension = dim2;
	 }
 }	     

 void vector::modElemen(int unsigned pos, double ele){
	 if(pos>=0 && pos<=dimension){
		 elementos[pos] = ele;
	 }
 }
 
 void vector::elimElem(int unsigned pos){
	 if(pos>=0 && pos<=dimension){
     for(int i=pos;i<=this->getDimension()-1;i++){
        elementos[i] = elementos[i+1];
		 }
		this->dimension = this->dimension-1; 
	 }
 }

 void vector::insertElem(int unsigned pos,double ele){
   if(pos>=0 && pos<=this->dimension){		 
		 this->dimension = this->dimension+1;
		 int unsigned i = this->dimension;
		   while(i>=pos+1){
	       this->elementos[i] = this->elementos[i-1];    			 
			 }
	 }   
 }

void vector::exchangeElement(int unsigned posA , int unsigned posB){
	if(posA >= 0 && posA <= dimension && posB >= 0 && posB <= dimension){
     double copiE = elementos[posA];
		 elementos[posA] = elementos[posB];
		 elementos[posB] = copiE;
	}
} 

 void vector::exchangeSort(){
	for(int unsigned i=0;i<dimension-1;i++){
		for(int unsigned j=i+1;j<dimension;j++){
      if(elementos[i] > elementos[j]){
				this->exchangeElement(i,j);
			}     	
		}
	}
 }

 void vector::selectionSort(){
  int unsigned ant;	
		for(int unsigned i=0;i<dimension-1;i++){			
		 ant = i;	
			for(int unsigned j=i+1;i<dimension;j++){
        if(elementos[ant] > elementos[j]) ant = j;				        
			}
			if(ant != i)  exchangeElement(ant,i);
		} 
 }

 void vector::shellSort(){
	int unsigned fact = this->dimension / 2;
	int unsigned i;
	bool sw;
	  while(fact > 0){
			sw = false;
			i = 0;
			 while(i < this->dimension-fact){
				 if(this->elementos[i] > this->elementos[i+fact]){
					 exchangeElement(i,i+fact);
					 sw = true;
				 }
				 i = i + 1;
			 }
			if(sw) fact = fact / 2;
		}		
 }

 void vector::MergeSort(){
	MSort(0,dimension);
 }

 void vector::MSort(int unsigned i , int unsigned f){
	int unsigned m;
	 if(i < f){
     m = (i+f) / 2;
		 MSort(i,m);
		 MSort(m+1,f);
		 Mezcla(i,m,f);
	 }
 }

 void vector::Mezcla(int unsigned i,int unsigned m,int unsigned f){
	 double VT[MAXE];
	 int unsigned k = i , l = m+1 , t = 1;
	  while(k < m && l < f){
       if(elementos[k] > elementos[l]){
				 VT[t] = elementos[k];
				 k = k + 1;
			 }else{
				 VT[t] = elementos[l];
				 l = l + 1;
			 }
			t = t + 1; 
		}
	while (k < m){
   VT[t] = elementos[k];
	 k = k + 1;
	 t = t + 1;
	}
	while(l < f){
		VT[t] = elementos[l];
		l = l + 1;
		t = t + 1;
	}
 t = 1;
  for(int x = i;x<f;x++) {
		elementos[x] = VT[t];
		t = t + 1;
	}
 }

//getters

 int vector::getDimension(){
  return dimension; 
 }

 double vector::getElemen(int unsigned pos){
	if(pos>=0 && pos<=dimension){
    return elementos[pos];
	}else{
		return 99999;
	}
 }

 double vector::mayorElem(){
	 double mayE = this->getElemen(0);
	  for(int unsigned i=1;i<this->dimension;i++){
      if(this->getElemen(i) > mayE){
				mayE = this->getElemen(i);
			}
		}
	return mayE;	
 }

 int unsigned vector::frecElem(double n){
   int unsigned i = 0;
	 int unsigned cont = 0;
	  while(i<this->dimension){
       if(this->getElemen(i) == n){
						cont = cont + 1;
			 }
			i++; 
		}
	return cont;	
 }

 int unsigned vector::busqLineal(double n){
		int unsigned i = 0;
		  while(i<this->dimension && (this->getElemen(i) != n)){
         i++;
			}
  if(this->getElemen(i) == n && i < dimension){
		 return i;
	}else{
		return 999999;
	} 
 }

 int unsigned vector::busqLinealOrdAsc(double n){
		int unsigned i = 0;
			while(i < this->dimension && this->getElemen(i) < n){
				i++;
			}		  
		if(i < this->dimension && this->getElemen(i) == n){
			return i; 
		}else return 99999;	
 }

 int unsigned vector::busqBinaria(double n){
   int unsigned sup = this->dimension,inf = 0,media = (sup+inf)/2;
	   while(inf <= sup &&  this->getElemen(media) != n){
        if(getElemen(media) == n) break;
				if(getElemen(media) > n){
	          sup = media - 1;				
				}else{
					inf = media + 1;
				}
				media = (sup+inf)/2;
		 } 
		if(getElemen(media) == n){
       return media;
		}else return 99999;
 }
