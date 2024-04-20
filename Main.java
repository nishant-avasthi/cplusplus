import java.util.*;

enum PaymentMode {
    UPI, CREDIT_CARD, DEBIT_CARD, NET_BANKING
}

class PaymentInstrument {
    private String upiId;
    private String cardNumber;
    private String expiryDate;
    private String cvv;
    private String userId;
    private String password;

    public PaymentInstrument(String upiId) {
        this.upiId = upiId;
    }

    public PaymentInstrument(String cardNumber, String expiryDate, String cvv) {
        this.cardNumber = cardNumber;
        this.expiryDate = expiryDate;
        this.cvv = cvv;
    }

    public PaymentInstrument(String userId, String password) {
        this.userId = userId;
        this.password = password;
    }

    public String getUpiId() {
        return upiId;
    }

    public String getCardNumber() {
        return cardNumber;
    }

    public String getExpiryDate() {
        return expiryDate;
    }

    public String getCvv() {
        return cvv;
    }

    public String getUserId() {
        return userId;
    }

    public String getPassword() {
        return password;
    }
}

class Bank {
    private String name;

    public Bank(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

class PaymentRouter {
    private Map<PaymentMode, Bank> modeToBankMapping;

    public PaymentRouter() {
        this.modeToBankMapping = new HashMap<>();
    }

    public void setRouting(PaymentMode mode, Bank bank) {
        modeToBankMapping.put(mode, bank);
    }

    public Bank routePayment(PaymentMode mode) {
        return modeToBankMapping.get(mode);
    }
}

class Client {
    private String name;
    private List<PaymentMode> supportedPaymentModes;

    public Client(String name) {
        this.name = name;
        this.supportedPaymentModes = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void addPaymentMode(PaymentMode mode) {
        supportedPaymentModes.add(mode);
    }

    public void removePaymentMode(PaymentMode mode) {
        supportedPaymentModes.remove(mode);
    }

    public List<PaymentMode> getSupportedPaymentModes() {
        return Collections.unmodifiableList(supportedPaymentModes);
    }
}
//PaymentGateway
public class Main {
    private Map<String, Client> clients;
    private Map<String, Bank> banks;
    private PaymentRouter paymentRouter;
    private Map<Bank, Double> bankDistribution;

    public Main() {
        this.clients = new HashMap<>();
        this.banks = new HashMap<>();
        this.paymentRouter = new PaymentRouter();
        this.bankDistribution = new HashMap<>();
    }

    public void addClient(Client client) {
        clients.put(client.getName(), client);
    }

    public void removeClient(String clientName) {
        clients.remove(clientName);
    }

    public boolean hasClient(String clientName) {
        return clients.containsKey(clientName);
    }

    public Set<PaymentMode> listSupportedPaymodes(String clientName) {
        if (!clients.containsKey(clientName))
            throw new IllegalArgumentException("Client not found");

        return new HashSet<>(clients.get(clientName).getSupportedPaymentModes());
    }

    public void addSupportForPaymode(String clientName, PaymentMode mode) {
        if (!clients.containsKey(clientName))
            throw new IllegalArgumentException("Client not found");
        
        System.out.println("Payment mode added as "+mode+ "for "+ clientName);
        clients.get(clientName).addPaymentMode(mode);
        
    }

    public void removePaymode(String clientName, PaymentMode mode) {
        if (!clients.containsKey(clientName))
            throw new IllegalArgumentException("Client not found");

        clients.get(clientName).removePaymentMode(mode);
    }

    public void configurePaymentRouting(PaymentMode mode, Bank bank) {
        paymentRouter.setRouting(mode, bank);
    }

    public void configureBankDistribution(Bank bank, double percentage) {
        bankDistribution.put(bank, percentage);
    }

    public void showDistribution() {
        for (Map.Entry<Bank, Double> entry : bankDistribution.entrySet()) {
            System.out.println(entry.getKey().getName() + ": " + entry.getValue() + "%");
        }
    }

    public void makePayment(String clientName, PaymentMode mode, PaymentInstrument instrument) {
        if (!clients.containsKey(clientName))
            throw new IllegalArgumentException("Client not found");

        Client client = clients.get(clientName);
        if (!client.getSupportedPaymentModes().contains(mode))
            throw new IllegalArgumentException("Client does not support this payment mode");

        Bank bank = paymentRouter.routePayment(mode);
        if (bank == null)
            throw new IllegalStateException("Payment routing not configured for this mode");

        double percentage = bankDistribution.getOrDefault(bank, 0.0);
        // Logic for processing payment and bank interaction can be added here
        System.out.println("Payment processed via " + bank.getName() + " for client " + clientName + " using " + mode);
    }

    public static void main(String[] args) {
        Main paymentGateway = new Main();
        Client flipkart = new Client("Flipkart");
        Client Shivani = new Client("Shivani");
        Shivani.addPaymentMode(PaymentMode.UPI);
        flipkart.addPaymentMode(PaymentMode.UPI);
        flipkart.addPaymentMode(PaymentMode.CREDIT_CARD);
        paymentGateway.addClient(flipkart);
        paymentGateway.addClient(Shivani);

        Bank hdfc = new Bank("HDFC");
        Bank icici = new Bank("ICICI");
        paymentGateway.banks.put("HDFC", hdfc);
        paymentGateway.banks.put("ICICI", icici);

        paymentGateway.configurePaymentRouting(PaymentMode.UPI, hdfc);
        paymentGateway.configurePaymentRouting(PaymentMode.CREDIT_CARD, icici);

        paymentGateway.configureBankDistribution(hdfc, 30.0);
        paymentGateway.configureBankDistribution(icici, 70.0);

        System.out.println("Distribution:");
        paymentGateway.showDistribution();

        PaymentInstrument upiInstrument = new PaymentInstrument("example@upi");
        PaymentInstrument cardInstrument = new PaymentInstrument("1234567890123456", "12/25", "123");
        paymentGateway.makePayment("Flipkart", PaymentMode.UPI, upiInstrument);
        paymentGateway.makePayment("Flipkart", PaymentMode.CREDIT_CARD, cardInstrument);
    }
}
