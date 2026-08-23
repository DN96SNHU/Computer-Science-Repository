import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ContactTest {
	
	@Test
	public void testContactCreationSuccess() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertEquals("123", c.getContactId());
		assertEquals("Freddy", c.getFirstName());
		assertEquals("Kruger", c.getLastName());
		assertEquals("1234567890", c.getPhone());
		assertEquals("444 Elm Street", c.getAddress());
	}
	
	@Test
	public void testContactIdTooLong() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("12345678901", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		
	}
	@Test
	public void testContactIdNull() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact(null, "Freddy", "Kruger", "1234567890", "444 Elm Street"));
	}
	
	@Test
	public void testFirstNameTooLong() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("123", "Freddyyyyyy", "Kruger", "1234567890", "444 Elm Street"));
	}
	@Test
	public void testLastNameTooLong() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("123", "Freddy", "Krugerrrrrr", "1234567890", "444 Elm Street"));
	}
	@Test
	public void testLastNameNull() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("123", "Freddy", null, "1234567890", "444 Elm Street"));
	}
	@Test
	public void testFirstNameNull() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact ("123", null, "Kruger", "1234567890", "444 Elm Street"));
	}
	@Test
	public void testPhoneNotTenDigits() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("123", "Freddy", "Kruger", "123456789", "444 Elm Street"));
	}
	
	@Test
	public void testPhoneTooLong() {
		assertThrows(IllegalArgumentException.class, () ->
				new Contact("123", "Freddy", "Kruger", "12345678901", "444 Elm Street"));
	}
	
	@Test
	public void testPhoneNonDigit() {
		assertThrows(IllegalArgumentException.class, () ->
				new Contact("123", "Freddy", "Kruger", "123456789a", "444 Elm Street"));
	}
	@Test
	public void testPhoneNull() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("123", "Freddy", "Kruger", null, "444 Elm Street"));
	}
	@Test
	public void testAddressTooLong() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("123", "Freddy", "Kruger", "1234567890", "444444444 Elm Street Springfield"));
	}
	@Test
	public void testAddressNull() {
		assertThrows(IllegalArgumentException.class, () ->
		new Contact("123", "Freddy", "Kruger", "1234567890", null));
				
	}
	@Test
	public void testSetFirstNameNull() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setFirstName(null));
	}
	@Test
	public void testSetFirstNameTooLong() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setFirstName("Freddyyyyyy"));
	}
	@Test
	public void testSetLastNameNull() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setLastName(null));
	}
	@Test
	public void testSetLastNameTooLong() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setLastName("Krugerrrrrr"));
	}
	@Test
	public void testSetPhoneNull() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setPhone(null));
	}
	@Test
	public void testSetPhoneInvalid() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setPhone("123456789"));
	}
	@Test
	public void testSetAddressNull() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setAddress(null));
	}
	@Test
	public void testSetAddressTooLong() {
		Contact c = new Contact("123", "Freddy", "Kruger", "1234567890", "444 Elm Street");
		assertThrows(IllegalArgumentException.class, () -> c.setAddress("444444444 Elm Street Springfield"));
	}

	 

}
