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
