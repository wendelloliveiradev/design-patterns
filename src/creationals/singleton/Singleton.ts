//Logging Service Singleton Class 
class LoggingServiceSingleton {
  private static instance: LoggingServiceSingleton;

  private constructor() {}

  public static getInstance(): LoggingServiceSingleton {
    if (!LoggingServiceSingleton.instance) {
      LoggingServiceSingleton.instance = new LoggingServiceSingleton();
    }

    return LoggingServiceSingleton.instance;
  }

  public log(message: string): void {
    console.log(message);
  }
}

//Client code
const logger = LoggingServiceSingleton.getInstance();
logger.log("This is a log message from the singleton logger");