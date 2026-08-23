
public class Contact {
	private final String contactId;
	private String firstName;
	private String lastName;
	private String phone;
	private String address;
	
	public Contact(String contactId, String firstName, String lastName, String phone, String address) {
		if (contactId == null || contactId.length() > 10)
			throw new IllegalArgumentException("Contact ID invalid");
		if (firstName == null || firstName.length() > 10)
			throw new IllegalArgumentException("First name invalid");
		if (lastName == null || lastName.length() > 10)
			throw new IllegalArgumentException("Last name invalid");
		if (phone == null || !phone.matches("\\d{10}"))
			throw new IllegalArgumentException("Phone number invalid");
		if (address == null || address.length() > 30)
			throw new IllegalArgumentException("Address invalid");
		
		this.contactId = contactId;
		this.firstName = firstName;
		this.lastName = lastName;
		this.phone = phone;
		this.address = address;
			
	}
	public String getContactId() {return contactId; }
	public String getFirstName() {return firstName; }
	public String getLastName() {return lastName;}
	public String getPhone() {return phone; }
	public String getAddress() {return address; }
	
	public void setFirstName(String firstName) {
		if (firstName == null || firstName.length() > 10)
			throw new IllegalArgumentException("First Name invalid");
		this.firstName = firstName;
	}
	public void setLastName(String lastName) {
		if (lastName == null || lastName.length() > 10)
			throw new IllegalArgumentException("Last name invalid");
		this.lastName = lastName;
	}
	
	public void setPhone(String phone) {
		if (phone == null || !phone.matches("\\d{10}"))
			throw new IllegalArgumentException("Invalid phone number");
		this.phone = phone;
	}
	public void setAddress(String address) {
		if (address == null || address.length() > 30)
			throw new IllegalArgumentException("Address invalid");
		this.address = address;
	}
		

}
