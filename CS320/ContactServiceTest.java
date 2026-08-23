import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ContactServiceTest {
	private ContactService service;
	
	@BeforeEach
	public void setUp() {
		service = new ContactService();
	}
	@Test
	public void testAddSingleContact() {
		service.addContact(new Contact("1", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		assertNotNull(service.getContact("1"));
	}
	@Test
	public void testAddMultipleContacts() {
		service.addContact(new Contact("1", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		service.addContact(new Contact("2", "Jason", "Voorhees", "0987654321", "555 Crystal Lake"));
		assertNotNull(service.getContact("1"));
		assertNotNull(service.getContact("2"));
	}
	@Test
	public void testAddDuplicateIdThrowsException() {
		service.addContact(new Contact("1", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		assertThrows(IllegalArgumentException.class, () ->
		service.addContact(new Contact("1", "Leather", "Face", "1111111111", "555 Elm Street")));
	}
	@Test
	public void testAddNullContactThrowsException() {
		assertThrows(IllegalArgumentException.class, () -> service.addContact(null));
	}
	@Test
	public void testAddAndGetContact() {
		service.addContact(new Contact("1", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		Contact retrieved = service.getContact("1");
		assertEquals("Freddy", retrieved.getFirstName());
		assertEquals("Kruger", retrieved.getLastName());
		
	}
	@Test
	public void testUpdateContactFields() {
		service.addContact(new Contact("1", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		service.updateFirstName("1", "Jason");
		service.updateLastName("1", "Voorhees");
		service.updatePhone("1", "0987654321");
		service.updateAddress("1", "555 Crystal Lake");
		Contact updated = service.getContact("1");
		assertEquals("Jason", updated.getFirstName());
		assertEquals("Voorhees", updated.getLastName());
		assertEquals("0987654321", updated.getPhone());
		assertEquals("555 Crystal Lake", updated.getAddress());
		
	}
	@Test
	public void testContactIdUnchangedAfterFieldUpdates() {
		service.addContact(new Contact("1", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		service.updateFirstName("1", "Jason");
		assertEquals("1", service.getContact("1").getContactId());
	}
	@Test
	public void testDeleteContact() {
		service.addContact(new Contact("1", "Freddy", "Kruger", "1234567890", "444 Elm Street"));
		service.deleteContact("1");
		assertNull(service.getContact("1"));
	}
	@Test
	public void testDeleteNonExistentContactThrowsException() {
		assertThrows(IllegalArgumentException.class, () -> service.deleteContact("999"));
	}
	@Test
	public void testUpdateNonExistentContactThrowsException() {
		assertThrows(IllegalArgumentException.class, () -> service.updateFirstName("999", "Jason"));
	}

}
