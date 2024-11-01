const int MAXE=1024;

class vector{

    private:
      int unsigned dimension;     	    
      double elementos[MAXE];
    public:
     //contructor 
       vector(); 
			 
     //GETTERS
      int getDimension();	
      double getElemen(int unsigned pos);
			double mayorElem();
			int unsigned frecElem(double n);
	   	//Busquedas	
        int unsigned busqLineal(double n);
				int unsigned busqLinealOrdAsc(double n);
				
				
      //Ordenamientos
        			  

     //SETTERS
      void setDimension(int unsigned dim2);
      void modElemen(int unsigned pos, double ele);
			void elimElem(int unsigned pos);
      void insertElem(int unsigned pos, double ele);
			
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
		  while(i<this->dimension && (this->getElemen(i) == n)){
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
			while(i < this->dimension && this->getElemen(i) <= n){
				i++;
			}		  
		if(i < this->dimension && this->getElemen(i) == n){
			return i; 
		}else return 99999;	
 }