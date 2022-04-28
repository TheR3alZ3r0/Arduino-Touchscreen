int readSamples(int port, int samples);

struct Package {

  public:

    void insertData(String data) {
      this->data = data;
    }
    void prepare(byte packageID, String syntaxType) {
      this->packageTimeStamp = millis();
      if (syntaxType == "json") {
        this->message = "{" + String(packageTimeStamp) + "|" + String(packageID) + "|" + data + "}";
      } else {
        this->message = String(packageTimeStamp) + "|" + String(packageID) + "|" + data;
      }
    }
    void sendPackage() {
      Serial.println(message);
    }
	void renewTimeStamp(){
		this->packageTimeStamp = millis();
	}

  private:

    unsigned long packageTimeStamp;
    byte packageID;
    String data;
    String message;

};

void readNew(int an1, int an2, int an3, int an4, int samples) {

  
  //Package pck = Package();
  //pck.insertData(msg);
  //pck.prepare(1, "json2");
  //pck.sendPackage();

}
